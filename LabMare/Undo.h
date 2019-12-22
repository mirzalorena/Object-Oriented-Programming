#pragma once
#include "Evidence.h"
#include "FileRepository.h"

class UndoAction
{
public:
	virtual ~UndoAction();
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};

class UndoAdd :public UndoAction
{
private:
	Evidence addedEvidence;
	Repository& repository;

public:
	void setAddedEvidence(Evidence newEvidence);
	void executeUndo() override;
	void executeRedo() override;
	UndoAdd(Evidence addedEvidence, Repository& repository);
};

class UndoRemove :public UndoAction
{
private:
	Evidence deletedEvidence;
	Repository& repository;

public:
	void setDeletedEvidence(Evidence newEvidence);
	void executeUndo() override;
	void executeRedo() override;
	UndoRemove(Evidence evidence, Repository& repository);

};

class UndoUpdate :public UndoAction
{
private:
	Evidence old;
	Evidence newEvidence;
	Repository& repository;

public:
	void setUpdatedEvidence(Evidence newEvidence);
	void executeUndo() override;
	void executeRedo() override;
	UndoUpdate(Evidence old, Evidence newEvidence, Repository& repository);
};